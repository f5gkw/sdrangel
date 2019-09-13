/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.11.6
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGPreset.h
 *
 * Represents a Preset object
 */

#ifndef SWGPreset_H_
#define SWGPreset_H_

#include <QJsonObject>


#include "SWGChannelConfig.h"
#include "SWGDeviceConfig.h"
#include "SWGGLSpectrum.h"
#include <QList>
#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGPreset: public SWGObject {
public:
    SWGPreset();
    SWGPreset(QString* json);
    virtual ~SWGPreset();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGPreset* fromJson(QString &jsonString) override;

    qint32 getPresetType();
    void setPresetType(qint32 preset_type);

    QString* getGroup();
    void setGroup(QString* group);

    QString* getDescription();
    void setDescription(QString* description);

    qint64 getCenterFrequency();
    void setCenterFrequency(qint64 center_frequency);

    SWGGLSpectrum* getSpectrumConfig();
    void setSpectrumConfig(SWGGLSpectrum* spectrum_config);

    qint32 getDcOffsetCorrection();
    void setDcOffsetCorrection(qint32 dc_offset_correction);

    qint32 getIqImbalanceCorrection();
    void setIqImbalanceCorrection(qint32 iq_imbalance_correction);

    QList<SWGChannelConfig*>* getChannelConfigs();
    void setChannelConfigs(QList<SWGChannelConfig*>* channel_configs);

    QList<SWGDeviceConfig*>* getDeviceConfigs();
    void setDeviceConfigs(QList<SWGDeviceConfig*>* device_configs);

    QString* getLayout();
    void setLayout(QString* layout);


    virtual bool isSet() override;

private:
    qint32 preset_type;
    bool m_preset_type_isSet;

    QString* group;
    bool m_group_isSet;

    QString* description;
    bool m_description_isSet;

    qint64 center_frequency;
    bool m_center_frequency_isSet;

    SWGGLSpectrum* spectrum_config;
    bool m_spectrum_config_isSet;

    qint32 dc_offset_correction;
    bool m_dc_offset_correction_isSet;

    qint32 iq_imbalance_correction;
    bool m_iq_imbalance_correction_isSet;

    QList<SWGChannelConfig*>* channel_configs;
    bool m_channel_configs_isSet;

    QList<SWGDeviceConfig*>* device_configs;
    bool m_device_configs_isSet;

    QString* layout;
    bool m_layout_isSet;

};

}

#endif /* SWGPreset_H_ */
